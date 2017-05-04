class CompressString(object):

    def compress(self, string):
        if string is None or not string:
            return string
        result = ''
        prev_char = string[0]
        count = 0
        for char in string:
            if char == prev_char:
                count += 1
            else:
                result += self._calc_partial_result(prev_char, count)
                prev_char = char
                count = 1
        result += self._calc_partial_result(prev_char, count)
        return result if len(result) < len(string) else string

    def _calc_partial_result(self, prev_char, count):
        return prev_char + (str(count) if count > 1 else '')
		
		
class TestCompress(object):

    def test_compress(self, func):
        assert_equal(func(None), None)
        assert_equal(func(''), '')
        assert_equal(func('AABBCC'), 'AABBCC')
        assert_equal(func('AAABCCDDDDE'), 'A3BC2D4E')
        assert_equal(func('BAAACCDDDD'), 'BA3C2D4')
        assert_equal(func('AAABAACCDDDD'), 'A3BA2C2D4')
        print('Success: test_compress')



compress_string = CompressString()
string = 'AAAAABBBBCCCDDE'
print compress_string.compress(string)
	