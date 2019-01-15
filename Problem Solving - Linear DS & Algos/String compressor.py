"""
String Compression
"ZZZBBA" will be converted to "Z3B2A"
07/10/2018
"""


class Code(object):

    def stringCompressor(self, sentence):

        if len(sentence) == 0:
            return ""

        compressedStr = ""
        count = 1
        for i in range(1, len(sentence)):
            if sentence[i] == sentence[i-1]:
                count += 1
            else:
                if count > 1:  # saving a byte
                    compressedStr += templetter + str(count)
                else:
                    compressedStr += templetter
                templetter = sentence[i]
                count = 1

        if count > 1:  # Last character+count was not appended due to above algorithm
            compressedStr += templetter + str(count)
        else:
            compressedStr += templetter
        return compressedStr


sentence = input("Enter your string: ").strip()
t = Code()
reversedSentence = t.stringCompressor(sentence)
print(reversedSentence)
