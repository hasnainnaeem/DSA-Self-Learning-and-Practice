"""
Reversing words in a sentence
07/10/2018
"""
class Code(object):
    def sentenceReversal(self, sentence):
        sentence = (sentence.strip()) + " "  # Adding space at end so every word has end space
        word = ""
        words =[]
        for i in range(len(sentence)):
            if sentence[i] != " ":
                word += sentence[i]
            else:
                words.append(word)
                word = ""

        return " ".join(reversed(words))


sentence = input("Enter sentence: ").strip()
t = Code()
reversedSentence = t.sentenceReversal(sentence)
print(reversedSentence)
