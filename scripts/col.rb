# desc: collects piles of specified foraging items and cleans up after
# requirements: ??
# run: valid foraging spot

Observer.instance.register_event({ :perc => "Roundtime" })

def perc
  echo Exp::state "perc"
end

if $args.empty?
  echo "Specify collectable item!"
  exit!
end

def kick_pile
  put "kick pile"
end

def finally_do
  pause_for_roundtime
  kick_pile
end

100.times do
  put "collect " + $args.join(" ")
  wait_for_roundtime
  kick_pile
end

Kernel::exit