find . -not -type d -name "*.sh" -execdir printf '%s\n' {} + | rev | cut -c 4- | rev
