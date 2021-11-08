import unittest

from modules.timer import timer
from modules.interactor import getContainer
from modules.order import inclusionSort


def runTestCase(input_filename, output_filename):
    try:
        input_file = open(input_filename, 'r')
        container = getContainer(input_file)
        input_file.close()

        inclusionSort(container)

        output_file = open(output_filename, 'w')
        output_file.write('\n'.join(map(lambda x: str(x), container)))
        output_file.close()

    except Exception:
        return False

    return True


class TestHomework(unittest.TestCase):

    def setUp(self):
        self.test_url = '../tests/test'
        self.res_url = '../results/res'
        self.extension = '.txt'

    def test_prepared(self):
        for i in range(1, 6):
            with self.subTest(i=i):
                input_filename = self.test_url + str(i) + self.extension
                output_filename = self.res_url + str(i) + self.extension
                self.assertEqual(runTestCase(input_filename, output_filename), True)

    def test_random(self):
        @timer
        def big():
            input_filename = self.test_url + 'random' + self.extension
            output_filename = self.res_url + 'random' + self.extension
            self.assertTrue(runTestCase(input_filename, output_filename))
        big()


def solution():
    unittest.main()


if __name__ == '__main__':
    solution()
