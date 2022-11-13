Blink SV
=====================

Setup
---------------------
Blink SV is an implementation of a node for the Blink SV network and is one of the pieces of software that provide 
the backbone of the network. It downloads and stores the entire history of Blink SV transactions (which is currently 
several GBs); depending on the speed of your computer and network connection, the synchronization process can take 
anywhere from a few hours to a day or more.

To download Blink SV, visit [blinksv.io](https://blinksv.io/).

Running
---------------------
Blink SV is only supported on the Linux and docker platforms at this time.

To run Blink SV on Linux:

* ensure that your system meets the minimum recommended [system requirements](https://blinksv.io/2019/08/02/blink-sv-node-system-requirements/)
* unpack the files into a directory
* run `bin/blinkd`

A docker image is available from https://hub.docker.com/r/blinksv/blink-sv. Images are tagged with 
the release version number. The `latest` tag is updated as new versions are released. The source for this image 
(Dockerfiles etc) is maintained in a GitHub repository: https://github.com/blink-sv/docker-sv. 
 
### Need Help?

* Log an issue on [GitHub] (https://github.com/blink-sv/blink-sv/issues)
* Ask for help on the [Blink SV Subreddit](https://www.reddit.com/r/blinkSV/) or
[Bictoin Cash SV Subreddit](https://www.reddit.com/r/blinkcashSV/).
* Consult [Blink SV Wiki](https://wiki.blinksv.io/) for information about Blink protocol.

Building
---------------------
The following are developer notes on how to build Blink. They are not complete guides, but include notes on the 
necessary libraries, compile flags, etc.

- [Unix Build Notes](build-unix.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Blink SV repo's [root README](/README.md) contains relevant information on the development process and automated 
testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Benchmarking](benchmarking.md)

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distribution is done under the [Open BSV License](/LICENSE). This product includes software developed by the OpenSSL 
Project for use in the [OpenSSL Toolkit](https://www.openssl.org/), cryptographic software written by Eric Young 
([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
