(defun tic-tac-toe ()
  (print 'tic-tac-toe)
  (terpri))

(defun my-ttt-list ()
  (print '(ttt-global-vars (round_counter mark game_over play_again_input spot_to_fill board_spots)))
  (terpri))

(defun my-functions ()
  (print '(ttt-functions (draw-board announce-three-in-a-row round-limit-checker display-info find-three-in-a-row change-turn attempt-to-fill-spot player-move start-game ask-to-play play-again reset-pregame-variables say-invaid)))
  (terpri))

(defun draw-board ()
  (tic-tac-toe)
  (my-ttt-list)
  (my-functions)
  (print'"


     |     |     
  0  |  1  |  2  
_____|_____|_____
     |     |     
  3  |  4  |  5  
_____|_____|_____
     |     |     
  6  |  7  |  8  
     |     |     


")(terpri))
