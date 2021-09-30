#!/bin/bash

mqtt-cli pub \
	-h bbc7140376e04bbda1238b9371fc2800.s2.eu.hivemq.cloud \
	-p 8883 \
	-s \
	-u cbries \
	-pw "Mynicepw!!!0" \
	-t 'cbries/sml' \
	-m '${args[${0}]}'

