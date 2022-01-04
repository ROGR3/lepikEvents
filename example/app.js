const lepikEvents = require("lepikevents");
lepikEvents.events.on("keyRelease", function (data) {
  console.log(data);
})
lepikEvents.events.on("mouseClick", function (data) {
  console.log(data)
})