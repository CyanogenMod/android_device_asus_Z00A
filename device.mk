#
# Copyright 2013 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

PRODUCT_PROPERTY_OVERRIDES += \
    ro.sf.lcd_density=480

# call dalvik heap config
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-dalvik-heap.mk)

# call hwui memory config
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-hwui-memory.mk)

DEVICE_PACKAGE_OVERLAYS := \
    device/asus/Z00A/overlay

# Boot image Signature
PRODUCT_COPY_FILES += \
    device/asus/Z00A/keys/boot_z00a.sig:install/bin/boot.sig

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.nfc.xml:system/etc/permissions/android.hardware.nfc.xml \
    frameworks/native/data/etc/android.hardware.nfc.hce.xml:system/etc/permissions/android.hardware.nfc.hce.xml

# NFC
PRODUCT_COPY_FILES += \
    device/asus/Z00A/nfc/libnfc-brcm.conf:system/etc/libnfc-brcm.conf \
    device/asus/Z00A/nfc/libnfc-brcm-20795a20.conf:system/etc/libnfc-brcm-20795a20.conf

ADDITIONAL_DEFAULT_PROPERTIES += \
    sys.nfc.project_id_str=ze551ml \
    sys.nfc.loc=gold \
    sys.nfc.brcm.cfg=/etc/libnfc-brcm.conf \
    sys.nfc.brcm.chip_cfg=/etc/libnfc-brcm-20795a20.conf \
    ro.nfc.conf=mofd-ffd2-a \
    ro.nfc.clk=pll

# NFC packages
PRODUCT_PACKAGES += \
    nfc_nci.bcm2079x.default \
    NfcNci \
    Tag

$(call inherit-product-if-exists, vendor/asus/Z00A/Z00A-vendor.mk)

# Inherit from mofd-common
$(call inherit-product, device/asus/mofd-common/mofd.mk)
