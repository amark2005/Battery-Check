bat=$(upower -e | grep BAT)
info=$(upower -i "$bat")

energy_full=$(awk '/energy-full:/ {print $2}' <<< "$info")
energy_full_design=$(awk '/energy-full-design:/ {print $2}' <<< "$info")

export energy_full="$energy_full"
export energy_full_design="$energy_full_design"

python3 calcu.py 