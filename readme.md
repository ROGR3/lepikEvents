# Lepik Events
An event based, Global Keyboard and Mouse listener.

[![NPM](https://nodei.co/npm-dl/lepikevents.png)](https://www.npmjs.com/package/lepikevents)

Lepik Events is only part from [LepikJS](https://www.npmjs.com/package/lepikjs). Definitely try it out



## Installing

    npm install lepikevents

## Coding

```javascript
// Require lepikEvents
const lepikEvents = require('lepikevents');

lepikEvents.events.on('keyPress', (data) => {
  // Returns key pressed as String 
  console.log(data); // e||esc||space||backspace ...
});

lepikEvents.events.on('keyRelease', (data) => {
  // Returns key released as String 
  console.log(data); // e||esc||space||backspace ...
});

lepikEvents.events.on('mouseClick', (data) => {
  // Returns array containing mouse position x, y and button clicked 
  console.log(data); // [361, 235, *1]
  // *1 for left, 2 for right, 3 for middle
});
```

## All events

Curently there are only 2 events, **mouseClick** and **keyPress**.
I will try to implement more in future.

## Requirements

Lepik Events uses [Python keyboard](https://github.com/boppreh/keyboard) and [Python mouse](https://github.com/boppreh/mouse) which runs on Python. 

If your are on Windows, then you don't even have to have it installed, cause thanks to [Pyinstaller](https://github.com/pyinstaller/pyinstaller), the code is compiled into executable.

If you are not using windows, you need to have atleast Python3 installed.
It's better to have atleast node13 but not required.


## License
The code is licensed under the MIT license (http://opensource.org/licenses/MIT). See LICENSE file.