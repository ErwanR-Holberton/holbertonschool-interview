#!/usr/bin/python3
"""
count
"""
import requests

def count_words(subreddit, word_list, after=None, word_count={}):
    headers = {'User-Agent': 'toto'} 
    params = {'limit': 100, 'after': after}
    response = requests.get("https://www.reddit.com/r/{}/hot.json".format(subreddit), headers=headers, params=params)
    data = response.json()
    posts = data['data']['children']
    word_list = [word.lower() for word in word_list]
    for post in posts:
        title = post['data']['title'].lower()
        words_in_title = title.split()

        for word in word_list:
            word_count[word] =  word_count.get(word, 0) + words_in_title.count(word)
    after = data['data'].get('after')
    if after:
        count_words(subreddit, word_list, after=after, word_count=word_count)
    else:
        for word, count in sorted(word_count.items(), key=lambda item: (-item[1], item[0])):
            if count > 0:
                print(f"{word}: {count}")
    return word_count