import unittest

from secret import _RESULTS
from CL_03 import *


class TestMethodify(unittest.TestCase):
    """Test metodify function."""

    def test_metodify(self):
        """Test metodify function."""
        self.assertIn(methodify(), _RESULTS.keys())


try:
    result = _RESULTS[methodify()]
    print("Резултат от контролното:\n"
          f"    {result['correct']}/30 верни отговора.\n"
          f"    {result['points']} точки.")
except:
    pass # No correct answer means no results

if __name__ == '__main__':
    unittest.main()