const fs = require('fs');
if (process.platform === "win32") {
  fs.rmdir(__dirname + "/../lib", { recursive: true }, (err) => {
    if (err) {
      throw err;
    }
  });
} else {
  fs.rmdir(__dirname + "/../build", { recursive: true }, (err) => {
    if (err) {
      throw err;
    }
  });
}
fs.unlink('./platform.js', (err) => {
  if (err) {
    throw err;
  }
});
