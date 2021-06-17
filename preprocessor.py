import nltk
from collections import defaultdict
from nltk.tokenize import sent_tokenize, RegexpTokenizer
from nltk.corpus import stopwords
from nltk.stem import snowball
import sys 
from common import stop_words, stemmer, word_tokenizer


def processor ( corpus ):
    corpus_words = []

    for c in corpus:
        for sentence in sent_tokenize(c):
            word_tokens = word_tokenizer.tokenize(sentence)
            corpus_words += word_tokens

    lower_case_words = set([x.lower() for x in corpus_words])

    stopfree_words = lower_case_words - stop_words

    stemmed_words = set([stemmer.stem(x) for x in stopfree_words])
    print(" ".join(stemmed_words))
    

if __name__ == '__main__':
    if len(sys.argv) <= 1:
        print ("Need more than one argument!")
    processor (sys.argv[1:])