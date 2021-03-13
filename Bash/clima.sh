#!/bin/bash
curl -o archivo_temporal wttr.in/Guatemala
head -7 archivo_temporal
rm archivo_temporal