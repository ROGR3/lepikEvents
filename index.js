const EventEmitter2 = require('eventemitter2').EventEmitter2;
const { spawn } = require('child_process');

const events = new EventEmitter2({ wildcard: true });
const python = process.platform === "win32" ? spawn(`${__dirname + '/src/win/winEvents.exe'}`) : spawn("sudo", ["python", `${__dirname + '/src/nix/unixEvents.py'}`]);

python.stdout.on('data', function (data) {
  data = data.toString().split(/\r\n|\r|\n/).filter(ar => { return ar })
  for (let str of data) {
    let ev = str.split(':');
    let ar = []
    try {
      ar = JSON.parse(ev.slice(1))
    } catch (er) {
      ar = ev.slice(1).toString().replace(" ", "")
    }
    events.emit(ev[0], ar);
  }
});

function killProcess(_pid) {
  spawn("taskkill", ["/pid", _pid, '/f', '/t']);
}



function cleanExit() {
  killProcess(python.pid)
  process.exit();
}

process.on('SIGINT', cleanExit);
process.on('SIGTERM', cleanExit);
process.on('exit', () => {
  killProcess()
});

module.exports = { events };
