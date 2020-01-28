# ZiaAPI
An API designed for an application server.

## Mediator

### The implementation of the server use the mediator design pattern. But why ?

When a module as finished processing its data, whe need a way to send it asynchronously to the server.
A great way of doing this is by using a meditor. How does it works ?

You pass a reference of the mediator (the "skeleton" object of your server) to all of your modules, but with the IMediator interface.
The interface has only one available method :
```notify(IModule *sender, Data &data);```

It can be then used to send data to the main thread, without touching to methods that modules aren't suppose to use.

Go check this link if you want more informations about the mediator design pattern : https://refactoring.guru/design-patterns/mediator

## Modules

### Modules inherites from the AModule abstract class, wich has several methods used to communicate with the mediator.

In short, modules are processing units that fetch data from the mediator and do something with it. When a module is processing some data, it sets the ```_status``` field to ```Processing```, wich tells the mediator that it isn't available for now.
When it's done processing data, it's sets the field to ```Done```, and when there's an error, ```Error```.

When they've done their work, they use the ```notify(IModule *sender, Data &data)``` method from the mediator to inform it of their work.

This way, the mediator decides whether it needs to send the data over another module, instanciate another module, stop the processing of the request because their was an error etc ...

All of the methods are documented inside header files. Go take a look.

## Data Structure

### Modules share their data between them using the ```Data``` structure.

The data structure has multiple fields.

### Request structure

By default, when the mediator get an http request, it feeds it to a request structure inside the ```raw_request``` field.

This way, a "request parser" module can fill up the rest of the structure from the raw request.

All fields are elements from the raw request, just parsed and fed to the structure, but it needs a module: this way, the mediator doesn't touch the request and data structure, it justs pass it around from modules to modules.

### Response structure

Same as the request structure, it is fed by modules, and forms the response that will be sent back to the client.

When all fields of the structure have been filled, a module "Response Sender" will fill the ```raw_response``` field, and then the mediator will send the response to the socket that sent the associated request.

If you want more information about fields of the data structure, check the header files, they are documented.

Their is an UML available in the repository (the "Zia" file). It can be read with draw.io.
This files contain all classes definition, with some example of the implementation of the server.

If you have any questions, please use the "issue" on this repository. Specifie wich topic you would like to discuss over, and, if you can, an example of the step to follow to reproduce your error.