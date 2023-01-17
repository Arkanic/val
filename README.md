# val
Get value of list of bitcoin wallets (ie electrum addresses) by their public keys

Intended purpose is just to check your wallets every so often without actually exposing/using any private keys on a computer. Uses blockchain.info api to query address values and current price of btc

## Usage

`./val wallet.txt`

returns

```
Sats: 100000000
BTC: 1.00BTC
Price: $20000
```

wallet.txt is a file of addresses separated by commas. All address formats work.

```
34xp4vRoCGJym3xR7yCVPFHoCNxv4Twseo
bc1qgdjqv0av3q56jvd82tkdjpy7gdp9ut8tlqmgrpmv24sq90ecnvqqjwvw97
3JJmF63ifcamPLiAmLgG96RA599yNtY3EQ
1LruNZjwamWJXThX2Y8C2d47QqhAkkc5os
```

## Building
Dependencies are libcurl-dev (web requests) and libjson-c-dev (json parsing), can be installed via `sudo apt-get install libcurl-4-dev libjson-c-dev`

Build:

```
make
./val // finished code
```


### Made by Arkanic