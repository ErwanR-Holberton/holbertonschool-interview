#!/usr/bin/python3
"""
count
"""
import requests

def print_list_recursive(lst):
    if not lst:
        return
    if lst[0][1] > 0:
        print("{}: {}".format(lst[0][0], lst[0][1]))
    print_list_recursive(lst[1:])

def count_recursive(word_count, word_list, words_in_title):
    if not word_list:
        return
    word_count[word_list[0]] = word_count.get(word_list[0], 0) + words_in_title.count(word_list[0])
    count_recursive(word_count, word_list[1:], words_in_title)

def recursive_post(posts, word_list, word_count):
    if not posts:
        return
    post = posts[0]
    title = post['data']['title'].lower()
    words_in_title = title.split()
    count_recursive(word_count, word_list, words_in_title)
    recursive_post(posts[1:], word_list, word_count)
    


headers = {'User-Agent': 'toto'} 
def count_words(subreddit, word_list, after=None, word_count={}):
    params = {'limit': 100, 'after': after}
    response = requests.get("https://www.reddit.com/r/{}/hot.json".format(subreddit), headers=headers, params=params)
    data = response.json()
    posts = data['data']['children']
    word_list = list(map(str.lower, word_list))

    recursive_post(posts, word_list, word_count)

    after = data['data'].get('after')
    if after:
        count_words(subreddit, word_list, after=after, word_count=word_count)
    else:
        print_list_recursive(sorted(word_count.items(), key=lambda item: (-item[1], item[0])))
    return word_count
    