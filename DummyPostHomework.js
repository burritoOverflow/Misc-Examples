const querystring = require('querystring');
const http = require('http');
const faker = require('faker');

// generate a dummy example for the homework server

const postData = querystring.stringify({
  "title": faker.fake("{{name.prefix}}"),
  "firstname": faker.fake("{{name.firstName}}"),
  "lastname": faker.fake("{{name.lastName}}"),
  "street": faker.fake("{{address.streetAddress}}"),
  "city": faker.fake("{{address.city}}"),
  "state": faker.fake("{{address.state}}"),
  "zip": faker.fake("{{address.zipCode}}"),
  "phone": faker.fake("{{phone.phoneNumber}}"),
  "email": faker.fake("{{internet.email}}"),
  "contactMail": "on",
  "contactEmail": "on",
  "contactPhone": "on",
  "contactAny": "on",
});

const options = {
  hostname: 'localhost',
  port: 8000,
  path: '/mailer',
  method: 'POST',
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded',
    'Content-Length': Buffer.byteLength(postData)
  }
};

let req = http.request(options, (res) => {
  console.log(`STATUS: ${res.statusCode}`);
  console.log(`HEADERS: ${JSON.stringify(res.headers)}`);
  res.setEncoding('utf8');
  res.on('data', (chunk) => {
    console.log(`BODY: ${chunk}`);
  });
  res.on('end', () => {
    console.log('No more data in response.');
  });
}).on('error', (e) => {
  console.error(`problem with request: ${e.message}`);
});
// Write data to request body
req.write(postData);
req.end();

