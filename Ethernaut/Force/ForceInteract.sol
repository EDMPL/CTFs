// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

import {ForceSend} from "./ForceSend.sol";

contract ForceInteract {
    ForceSend public forceSend;
    uint256 public constant AMOUNT = 0.000000001 ether;

    constructor() payable {
        require(msg.value >= AMOUNT, "Need some ether to send");
        forceSend = new ForceSend{value: AMOUNT}(payable(address(0x3Bef555bf93dbf5A2bC73b041821009379217FD9)));
    }
}
