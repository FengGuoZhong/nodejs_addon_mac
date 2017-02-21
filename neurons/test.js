var addon = require('./build/Release/neurons.node');

var data = "1,3,2,44,45,55";
console.log( 'Learn:', addon.Learn(data) );


data = "0,3,44,45,55";
console.log( 'Classify:', addon.Classify(data) );