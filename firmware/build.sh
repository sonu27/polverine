#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

if [ ! -f "$SCRIPT_DIR/main/config.h" ]; then
    echo "Error: main/config.h not found. Copy main/config.example.h to main/config.h and edit it."
    exit 1
fi

docker run --rm \
    -v "$PROJECT_DIR":/project \
    -w /project/firmware \
    espressif/idf:v5.5.3 \
    idf.py build
