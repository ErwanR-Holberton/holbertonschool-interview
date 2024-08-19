#!/usr/bin/node
const request = require('request');

if (process.argv[2] === undefined) {
  console.log('Usage: node 0-starwars_characters.js <film id>');
  process.exit();
}

function requestPromise (url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true }, (error, response, body) => {
      if (error) {
        reject(error);
      } else if (response.statusCode !== 200) {
        reject(new Error(`Failed request. Status code: ${response.statusCode}`));
      } else {
        resolve(body);
      }
    });
  });
}

async function logName (url) {
  try {
    const data = await requestPromise(url);
    console.log(data.name);
  } catch (error) {
    console.error('Error fetching character:', error.message);
  }
}

async function getCharacters () {
  try {
    const filmData = await requestPromise('https://swapi-api.hbtn.io/api/films/' + process.argv[2]);
    const characterUrls = filmData.characters;

    for (const url of characterUrls) {
      await logName(url);
    }
  } catch (error) {
    console.error('Failed request:', error.message);
  }
}

getCharacters();
