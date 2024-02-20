import unittest
import json
import jsonschema
import referencing
import hypothesis
from hypothesis import strategies as st


class TestSchemas(unittest.TestCase):
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
            'question_path': st.text(min_size=1),
            'submitted_files': st.lists(st.text(), min_size=1, unique=True)
        },
        optional={
            'comment': st.text(),
            'number_of_matches_to_show': st.integers(min_value=1),
            'language': moss_language,
            'max_appearances': st.integers(min_value=1),
            'base_files': st.lists(st.text(), unique=True)
        })

    @classmethod
    def setUpClass(cls):
        super().setUpClass()
        with (open('../schemas/moss_languages.schema.json') as language_schema_file,
              open('../schemas/question.schema.json') as question_schema_file):
            cls.languages_schema = referencing.Resource.from_contents(json.load(language_schema_file))
            cls.question_schema = json.load(question_schema_file)
            cls.registry = referencing.Registry().with_resources([
                (
                'https://github.com/mfbutner/PrairieLearnEasyMoss/blob/main/languages.moss.json', cls.languages_schema),
                ('urn:moss_languages', cls.languages_schema),
                ('https://github.com/mfbutner/PrairieLearnEasyMoss/blob/main/question.schema.json',
                 referencing.Resource.from_contents(cls.question_schema)),
                ('urn:question', referencing.Resource.from_contents(cls.question_schema))
            ])

    @hypothesis.given(question_json)
    def test_valid_question_specifications(self, question):
        jsonschema.validate(question, self.question_schema, registry=self.registry)


if __name__ == '__main__':
    unittest.main()
