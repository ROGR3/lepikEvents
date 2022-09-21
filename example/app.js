const lepikEvents = require("../index.js");
lepikEvents.events.on("keyPress", function (data) {
  console.log(data);
})
lepikEvents.events.on("mouseClick", function (data) {
  console.log(data)
})
lepikEvents.events.on("mouseMove",function(data){
  console.log(data);
})