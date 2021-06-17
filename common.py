import nltk
from nltk.corpus import stopwords
from nltk.tokenize import RegexpTokenizer
from nltk.stem import snowball

stop_words = set(stopwords.words('english'))
stemmer = snowball.SnowballStemmer('english')
word_tokenizer = RegexpTokenizer(r'\w+')
