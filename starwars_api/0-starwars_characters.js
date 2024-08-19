#!/usr/bin/node
const request = require('request');

if (process.argv[2] == undefined)
{
	console.log("Usage: node 0-starwars_characters.js <film id>");
	exit();
}

async function log_name(url) {

	const options = {
		url: url,
		method: 'GET',
		headers: { 'Content-Type': 'application/json' }
	};

	request(options, (error, response, body) => {
		if (error) { console.error('Error making request:', error); return; }

		if (response.statusCode === 200) {

		console.log(JSON.parse(body).name);

		} else { console.error('Failed request. Status code:', response.statusCode); }
	});
}


const options = {
	url: "https://swapi-api.hbtn.io/api/films/" + process.argv[2],
	method: 'GET',
	headers: { 'Content-Type': 'application/json' }
};

request(options, (error, response, body) => {
  if (error) { console.error('Error making request:', error); return; }

  if (response.statusCode === 200) {

	JSON.parse(body)["characters"].forEach(element => {
		options.url = element;
		log_name(element);
	});;

  } else { console.error('Failed request. Status code:', response.statusCode); }
});
