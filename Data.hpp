
#pragma once

#include <unordered_map>
#include <string>

/// \namespace Zia
/// \brief The Zia web server namespace.
namespace Zia
{
    /// \struct Request
    /// \brief Structure containing request informations
    struct Request
    {
        /*! String containing the method of the request (GET, POST ...) */
        std::string method;

        /*! String containing the uri of the request */
        std::string requesturi;

        /*! String containing the http version */
        std::string http_version;

        /*! map of all headers in the request associated with their values respectively */
        std::unordered_map<std::string, std::string> headers;

        /*! String containing only the content of the request's body */
        std::string body_content;

        /*! String containing the request as it is received */
        std::string raw_resquest;
    };

    /// \struct Response
    /// \brief Structure containing response informations
    struct Response
    { 
        /* String containing the http version of the response */
        std::string http_version;

        /* String containing the response's status code */
        std::string status_code;

        /* String containing the response's reason phrase */
        std::string reason_phrase;

        /* Map containing all headers of the response */
        std::unordered_map<std::string, std::string> headers;

        /* String containing the response body */
        std::string body_content;

        /* String containing the current type of the response (ex: py, php ...) */
        std::string type;

        /*! String containing the respond as it will be send */ 
        std::string raw_response;
    };

    /// \struct Data
    /// \brief Structure containing request and response informations
    struct Data
    {
        /* Structure containing request informations */
        Request request;

        /* Structure containing response informations */
        Response response;
    };
}
