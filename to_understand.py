import nltk
from collections import defaultdict
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import stopwords
from nltk.stem import snowball

corpus_words = []

#This is tokkenizing a paragraph into sentences and 
#each sentence into words which is being stored in
#the list above

for c in corpus:
    for sentence in sent_tokenize(c):
        word_tokens = word_tokenize(sentence)
        corpus_words += word_tokens



#Since other than in specialised scenarios, we shall
#not need to differentiate between upper, lower and
#mixed case words, we shall convert all of them to
#lower case

lower_corpus_words = set([x.lower(), for x in corpus_words])


#Finding the stopwords of the english language

stop_words = set(stopwords.words('english'))

#Using set difference to remove stopwords from our data

stopfree_words = lower_corpus_words - stop_words

#len after all these operations will be lower
#thus making any operation we do with our data faster

#stemming the data we have obtained

stemmer = snowball.SnowballStemmer('english')
stemmed_words = set([stemmer.stem(x) for x in stopfree_words])