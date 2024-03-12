import unittest
import json
import jsonschema
import referencing
import hypothesis
from hypothesis import strategies as st

moss_language = st.sampled_from([
    "a8086",
    "ada",
    "ascii",
    "c",
    "cc",
    "csharp",
    "fortran",
    "haskell",
    "java",
    "javascript",
    "lisp",
    "matlab",
    "mips",
    "ml",
    "modula2",
    "pascal",
    "perl",
    "plsql",
    "prolog",
    "python",
    "scheme",
    "spice",
    "vb",
    "verilog",
    "vhdl"
])
question_json = st.fixed_dictionaries(
    {
        'question_name': st.text(min_size=1),
        'submitted_files': st.lists(st.text(min_size=1, max_size=1), min_size=1, max_size=3, unique=True)
    },
    optional={
        'question_path': st.text(min_size=1, max_size=1),
        'comment': st.text(max_size=1),
        'number_of_matches_to_show': st.integers(min_value=1, max_value=2),
        'language': moss_language,
        'max_appearances': st.integers(min_value=1, max_value=2),
        'base_files': st.lists(st.text(min_size=1, max_size=1), max_size=2, unique=True)
    })

easy_moss_json = st.fixed_dictionaries(
    {'assignment_info': st.lists(question_json, min_size=1, max_size=10, unique_by=lambda x: x['question_name'])},
    optional={'question_path': st.text(min_size=1, max_size=1),
              'comment': st.text(max_size=1),
              'number_of_matches_to_show': st.integers(min_value=1, max_value=2),
              'language': moss_language,
              'max_appearances': st.integers(min_value=1, max_value=2)
              }
)


@st.composite
def valid_easy_moss_config(draw, easy_moss_config):
    global moss_language
    question_required_fields = {'question_path': st.text(min_size=1),
                                'language': moss_language}
    easy_moss_config_example = draw(easy_moss_config)
    for question in easy_moss_config_example['question_info']:
        for required_field, strategy in question_required_fields.items():
            if required_field not in easy_moss_config_example and required_field not in question:
                question[required_field] = draw(strategy)
    return easy_moss_config_example


class TestSchemas(unittest.TestCase):
    question_required_fields = ('question_path', 'language')

    @classmethod
    def setUpClass(cls):
        super().setUpClass()
        with (open('../schemas/moss_languages.schema.json') as language_schema_file,
              open('../schemas/question_overridables.schema.json') as question_overridables_file,
              open('../schemas/question.schema.json') as question_schema_file,
              open('../schemas/easy_moss_config.schema.json') as easy_moss_schema_file):
            cls.languages_schema = json.load(language_schema_file)
            cls.question_overridables_schema = json.load(question_overridables_file)
            cls.question_schema = json.load(question_schema_file)
            cls.easy_moss_schema = json.load(easy_moss_schema_file)
            cls.registry = referencing.Registry().with_resources([
                (
                    'https://github.com/mfbutner/PrairieLearnEasyMoss/blob/main/languages.moss.json',
                    referencing.Resource.from_contents(cls.languages_schema)),
                ('urn:moss_languages', referencing.Resource.from_contents(cls.languages_schema)),
                ('https://github.com/mfbutner/PrairieLearnEasyMoss/blob/main/question_overridables.schema.json',
                 referencing.Resource.from_contents(cls.question_overridables_schema)),
                ('urn:question_overridables', referencing.Resource.from_contents(cls.question_overridables_schema)),
                ('https://github.com/mfbutner/PrairieLearnEasyMoss/blob/main/question.schema.json',
                 referencing.Resource.from_contents(cls.question_schema)),
                ('urn:question', referencing.Resource.from_contents(cls.question_schema))
            ])

    @hypothesis.settings(max_examples=10_000, deadline=None)
    @hypothesis.given(question_json)
    def test_valid_question_specifications(self, question):
        jsonschema.validate(question, self.question_schema, registry=self.registry)

    @hypothesis.settings(max_examples=10_000, deadline=None)
    @hypothesis.given(easy_moss_json)
    def test_easy_moss_config(self, easy_moss_config):
        for question in easy_moss_config['assignment_info']:
            for question_required_field in self.question_required_fields:
                # if a question required field is missing at both the global level and in a question
                if question_required_field not in easy_moss_config and question_required_field not in question:
                    # the json is invalid and doesn't match the schema
                    with self.assertRaises(jsonschema.exceptions.ValidationError):
                        jsonschema.validate(easy_moss_config, self.easy_moss_schema, registry=self.registry)
                    return
        jsonschema.validate(easy_moss_config, self.easy_moss_schema, registry=self.registry)


if __name__ == '__main__':
    unittest.main()
