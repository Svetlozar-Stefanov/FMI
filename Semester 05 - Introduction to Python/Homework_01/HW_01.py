def outer_size(word_size):
    o_size = word_size // 3
    if word_size % 3 == 2:
        o_size += 1
    return o_size

def middle_size(word_size):
    m_size = word_size // 3
    if word_size % 3 == 1:
        m_size += 1
    return m_size

def beginning(word):
    end = outer_size(len(word))
    return word[:end]

def middle(word):
    start = outer_size(len(word))
    end = start + middle_size(len(word))
    return word[start:end]

def end(word):
    start = outer_size(len(word)) + middle_size(len(word))
    return word[start:]

def split_sentence(sentence):
    spl_sentence = []
    for word in sentence.split():
        spl_word = (beginning(word), middle(word), end(word))
        spl_sentence.append(spl_word)
    return spl_sentence