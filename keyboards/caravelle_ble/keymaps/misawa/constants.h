#pragma once
#include QMK_KEYBOARD_H

enum layer_ids {
    LAYER_QWERTY = 0,
    LAYER_WORKMAN,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE, // Set QWERTY as the default layout
    KC_WORKMAN,             // Set Workman as the default layout

    // BLE-related
    AD_WO_L,                // Start advertising without whitelist
    BLE_DIS,                // Disable BLE HID sending
    BLE_EN,                 // Enable BLE HID sending
    USB_DIS,                // Disable USB HID sending
    USB_EN,                 // Enable USB HID sending
    DELBNDS,                // Delete all bonding
    ADV_ID0,                // Start advertising to PeerID 0
    ADV_ID1,                // Start advertising to PeerID 1
    ADV_ID2,                // Start advertising to PeerID 2
    ADV_ID3,                // Start advertising to PeerID 3
    ADV_ID4,                // Start advertising to PeerID 4
    BATT_LV,                // Display battery level in milli volts
    DEL_ID0,                // Delete bonding of PeerID 0
    DEL_ID1,                // Delete bonding of PeerID 1
    DEL_ID2,                // Delete bonding of PeerID 2
    DEL_ID3,                // Delete bonding of PeerID 3
    DEL_ID4,                // Delete bonding of PeerID 4
    ENT_DFU,                // Start bootloader
    ENT_SLP,                // Deep sleep mode
};

