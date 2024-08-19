#!/usr/bin/node
const request = require('request');

if (process.argv[2] == undefined)
{
	console.log("Usage: node 0-starwars_characters.js <film id>");
	exit();
}

const options = {
  url: 'https://swapi-api.hbtn.io/api/people/',
  method: 'GET',
  headers: { 'Content-Type': 'application/json' }
};

request(options, (error, response, body) => {
  if (error) { console.error('Error making request:', error); return; }

  if (response.statusCode === 200) {

	const info = JSON.parse(body);
	info["results"].forEach(element => {
		if (element.films.includes("https://swapi-api.hbtn.io/api/films/" + process.argv[2] + '/'))
			console.log(element.name);
	});

  } else { console.error('Failed request. Status code:', response.statusCode); }
});
