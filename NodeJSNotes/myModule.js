var http = require('http');
var fs = require('fs');


module.exports = {
  // reads file contents, pass the callback in the program that
  // uses it
  returnFileContents: function(filename, callback) {
    fs.readFile(filename, callback);
  },

  //create a server object, take content as arg,
  // return as response
  server: function(content, port) {
    http.createServer(function (req, res) {
      res.write(content);
      res.end();
    }).listen(port, console.log(`Server running on port ${port}`))
  }
}
