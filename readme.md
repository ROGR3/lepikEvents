# Lepik Events
An event based, Global Keyboard and Mouse listener.

[![NPM](https://nodei.co/npm-dl/lepikevents.png)](https://www.npmjs.com/package/lepikevents)

Lepik Events is only part from [LepikJS](https://www.npmjs.com/package/lepikjs). Definitely try it out!

Visit LepikJS's [website](https://lepikjs.netlify.app/).

## Installing

    npm install lepikevents

> ㅤ
> ## New Feature v1.6.0+
>
> **LepikEvents now includes a method for capturing mouse move event!**
>
> > [lepikevents.events.on("mouseMove", cb)](#all-events)
> 
> **JS object is passed to callback function. It contain these values:** *x, y, time*
> ㅤ
>  ㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤLepikEventsv1.6.0

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

lepikEvents.events.on('mouseDoubleClick', (data) => {
  // Returns array containing mouse position x, y and button double-clicked 
  console.log(data); // [361, 235, *1]
  // *1 for left, 2 for right, 3 for middle
});

lepikEvents.events.on('mouseMove', (data) => {
  // Returns array containing mouse x, y and time (seconds)
  console.log(data); // [20, -35, 1663787912.698]
});
```

## All events

Curently there are 5 events in total, **mouseMove**, **mouseClick**, **mouseDoubleClick**, **keyPress** and **keyRelease**.

## Requirements

Lepik Events uses [Python keyboard](https://github.com/boppreh/keyboard) and [Python mouse](https://github.com/boppreh/mouse) which runs on Python. 

If your are on Windows, then you don't even have to have it installed, cause thanks to [Pyinstaller](https://github.com/pyinstaller/pyinstaller), the code is compiled into executable.

If you are not using windows, you need to have atleast Python3 installed.
It's better to have atleast node13 but not required.

## License
The code is licensed under the MIT license (http://opensource.org/licenses/MIT). See [LICENSE](./LICENSE) file.