const hello = require('./myModule.js');

// provide a file to read as arg, pass the contents of this
// file as the content to be returned in the server's response
hello.sayFile(process.argv[2], function(err, contents) {
  if (err) {
    console.error(err);
  }
  hello.server(contents);
});
