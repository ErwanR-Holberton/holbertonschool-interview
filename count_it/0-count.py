#!/usr/bin/python3
"""
0-count
"""
import requests as req


def count_words(subreddit, word_list, occurences=None, after=''):
    """Count the occurences of each word
    in the title of all hot article of a subreddit
    """

    if occurences is None:
        word_list = [w.lower() for w in word_list]
        occurences = dict.fromkeys(set(word_list), 0)

    headers = {'User-agent': 'python:count_it:v0.1 (by u/judgedead53)'}
    r = req.get('https://www.reddit.com/r/{}/hot.json?after={}&limit=100'
                .format(subreddit, after), headers=headers)

    if r.status_code != 200:
        return

    data = r.json()['data']
    for data_entry in data['children']:
        title = data_entry['data']['title'].lower()
        title_words = title.split(' ')
        for word in word_list:
            occurences[word] += title_words.count(word.lower())

    if 'after' in data and data['after'] is not None:
        count_words(subreddit, word_list, occurences, data['after'])
    else:
        sorted_items = sorted(occurences.items(),
                              key=lambda item: (-item[1], item[0]))
        for (k, v) in sorted_items:
            if v <= 0:
                continue
            print('{}: {}'.format(k, v))
