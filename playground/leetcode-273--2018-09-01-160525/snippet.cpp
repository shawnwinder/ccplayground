// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (23.12%)
 * Total Accepted:    68.9K
 * Total Submissions: 298.1K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 231 - 1.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: "One Hundred Twenty Three"
 *
 *
 * Example 2:
 *
 *
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 *
 * Example 3:
 *
 *
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 *
 *
 * Example 4:
 *
 *
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 *
 *
 */
var (
	words [1000]string
)

func init() {
	words[0] = ""
	words[1] = " One"
	words[2] = " Two"
	words[3] = " Three"
	words[4] = " Four"
	words[5] = " Five"
	words[6] = " Six"
	words[7] = " Seven"
	words[8] = " Eight"
	words[9] = " Nine"
	words[10] = " Ten"
	words[11] = " Eleven"
	words[12] = " Twelve"
	words[13] = " Thirteen"
	words[14] = " Fourteen"
	words[15] = " Fifteen"
	words[16] = " Sixteen"
	words[17] = " Seventeen"
	words[18] = " Eighteen"
	words[19] = " Nineteen"
	words[20] = " Twenty"
	words[30] = " Thirty"
	words[40] = " Forty"
	words[50] = " Fifty"
	words[60] = " Sixty"
	words[70] = " Seventy"
	words[80] = " Eighty"
	words[90] = " Ninety"

	for i := 20; i < 100; i += 10 {

		for j := 1; j < 10; j++ {

			words[i+j] = words[i] + words[j]
		}
	}

	for i := 1; i < 10; i++ {

		for j := 0; j < 100; j++ {

			words[i*100+j] = words[i] + " Hundred" + words[j]
		}
	}
}

func numberToWords(num int) string {
    	if num == 0 {
		return "Zero"
	}
	words[0] = " "

	ret := ""
	if res := num / 1000000000; res > 0 {

		ret += words[res] + " Billion"
		num = num % 1000000000

	}

	if res := num / 1000000; res > 0 {

		ret += words[res] + " Million"
		num = num % 1000000

	}

	if res := num / 1000; res > 0 {

		ret += words[res] + " Thousand"
		num = num % 1000

	}

	ret += words[num]

	return strings.TrimSpace(ret)
}


int mymain(int argc, char *argv[]) {
    return 0;
}
