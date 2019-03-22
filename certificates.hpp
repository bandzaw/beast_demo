#pragma once 

#include <string>
#include <boost/asio/ssl/context.hpp>

static void loadCertificates(   
    boost::asio::ssl::context& ctx,
    const std::string& cafile,
    const std::string& crtfile,
    const std::string& keyfile,
    boost::system::error_code& ec)
{
    ctx.load_verify_file(cafile, ec);
    if (ec) return;

    ctx.use_certificate_file(crtfile, boost::asio::ssl::context_base::pem, ec);
    if (ec) return;

    ctx.use_certificate_chain_file(crtfile, ec);
    if (ec) return;

    ctx.use_private_key_file(keyfile, boost::asio::ssl::context_base::pem, ec);
    if (ec) return;
}
