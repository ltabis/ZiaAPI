# ZiaAPI
An API designed for an application server.

## Mediator

### The implementation of the server use the mediator design pattern. But why ?

When a module is done processing its data, whe need a way to send it asynchronously to the server.
A great way of doing this is by using a mediator. How does it works ?

You give a reference of the mediator (the "skeleton" object of your server) to all of your modules, but through the IMediator interface.
The interface has only one available method :
```notify(IModule *sender, Data &data);```

Then it can be used to send data to the main thread (because each module is threaded), without accessing methods that modules aren't suppose to use.

Go check this link if you want more informations about the mediator design pattern : https://refactoring.guru/design-patterns/mediator

## Modules

### Modules inherites from the AModule abstract class, wich has several methods used to communicate with the mediator.

In short, modules are processing units that fetch data from the mediator and do something with it. When a module is processing some data, it sets the ```_status``` field to ```Processing```, wich tells the mediator that it isn't available for now.
When it's done processing data, it sets the field to ```Done```, and when there's an error, it sets the field to ```Error```.

When they've done their work, they use the ```notify(IModule *sender, Data &data)``` method from the mediator to inform they are done.

This way, the mediator decides whether it needs to send the data to another module, instanciate another module, stop the processing of the request because there was an error etc ...

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
This file contain all classes definition, with some example of the implementation of the server.

If you have any questions, please use the "issue" on this repository. Specifie wich topic you would like to discuss over, and, if you can, an example of the step to follow to reproduce your error.

## Configuration

### This API uses JSON files to configurate the server.

The main file, called config.json, will have the following fields:

```
{
    "server": {
        port: 80,
        module_folder: "/home/user/zia/modules",
        home_folder: "/home/user/zia/index"
    }
}
```
- **port**
    The port of the server to connect to.
    *Set to 80 by default*.
- **module_folder**
    The folder where the modules will be located (.so and .dll files).
    *Set to /home/srv/index/ by default*. 
- **home_folder**
    The current working directory of the server.
    *Set to /home/srv/index by default*. 

A module configuration file, called modules.json, will describe modules to be loaded and their characteristics. It can contain the following fields:

```
{
    "SSL/TLS" : {
        "max_instance": 10,
        "max_request": 5,
        "timeout": 2000,
        "extra_config": /home/usr/someone/ssl.conf
    }
    "PhpCGI" : {
        "max_instance": 20,
        "max_request": 3,
        "http_version": "1.0"
    }
}
```
- **max_instance**
    The number of modules from the same type that the server can hold running at the same time.
    *Set to unlimited by default*. 
- **max_request**
    When the server send requests to the module, if this one is still processing, it can decide if it needs to instanciate another module to fluidify data processing between requests. This field is set for this purpose.

    *for example:* if the PhpCGI is still processing a request while the server tries to feed it 3 or more requests at the same time, the server can instanciate another PhpCGI module to sent it the other requests.
    *Set to unlimited by default*.
- **timeout**
    The time between each process of a module in milliseconds. If a module, while processing data, exeeds this time limit, the server will kill the process and send an error code to the client.
    *Set to none by default*.
- **http_version**
    The http version handled by the module (for retrocompatibility).
    *Set to 1.1 by default*.

- **extra_config**
    Configuration file that the module will use to configure itself. (for example, the ssl key for a secure connection module.)
    *No file set by default*.