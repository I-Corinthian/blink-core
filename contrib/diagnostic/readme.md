# Diagnostic service script

Script `blink-diag.sh` can help you identify problems that you may encounter while running the BlinkSV node.
It is intended to be used on Linux.

## How to use it

1. Make sure that your BlinkSV node (`blinkd`) is up and running.
2. Check __RPC settings__ on your node (rpcuser, rpcpassword, rpcport). These settings are provided either in the configuration file or as command-line arguments to the `blinkd`.
3. The `blink-diag.sh` script needs a full path to the `blink-cli`. Alternatively you can put the path to the $PATH environment variable.
4. Run the script in __test mode__ to make sure RPC connection is successful. \
`blink-diag.sh --blinkcli <BLINK_CLI> --rpcuser <RPC_USER> --rpcpassword <RPC_PASSWORD> --rpcport <RPC_PORT> --test ` 

If your RPC settings and the `<BLINK_CLI>` path are correct, you should get the following output:

> Warning: You should never share your RPC settings with anyone that you don't want to access your node.


```json
RPC USER                  = <RPC_USER>
RPC PASSWORD              = <RPC_PASSWORD>
RPC PORT                  = <RPC_PORT>
RPC ADDRESS               = <RPC_ADDRESS>
BLINKCLI                = <BLINK_CLI>
BLINKCLI_CHECK          = OK
RPC_CONNECTION            = OK
```
The script will run system functions. If some of them do not exist on your sytem installed, you will see the following warnings:

`WARNING: <function> doesn't exist. We won't be able to get some data about your system `

5. Run the same command as in previous step (4.) but without the `--test` flag. To save the output to a file add `> report.json` to the end of the command. \
`blink-diag.sh --blinkcli <BLINK_CLI> --rpcuser <RPC_USER> --rpcpassword <RPC_PASSWORD> --rpcport <RPC_PORT> > report.json`

> `bitcin-diag.sh` script can execute RPC commands on the remote machine (by providing --rpcaddress), but this is not recommended because it cannot obtain system information from the remote machine running the BlinkSV node.

You may need to wait for a few seconds for the blink-diag.sh script to generate diagnostic report about BlinkSV node. The report is stored in the `report.json` file.

> If you don't want to include your config settings in this report please use `--dontdumpconfig` parameter. Note that sensitive data like rpcuser, rpcpassword and rpcauth is never included in the report.
