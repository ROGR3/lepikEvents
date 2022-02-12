const fs = require('fs');

fs.copyFile('src/winpy.py', 'lib/unixpy.py', (err) => {
  if (err) throw err;
});