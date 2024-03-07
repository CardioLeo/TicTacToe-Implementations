(defun tic-tac-toe ()
  (print 'tic-tac-toe)
  (terpri))

(defvar *false* 'false)
(defvar *game_over* *false*)
(defvar *found_a_match* *false*)

(defun my-ttt-list ()
  (print '(ttt-global-vars (round_counter mark play_again_input spot_to_fill board_spots)))
  (print '"The variable game_over is set to: ")
  (print *game_over*)
  (print '"and the varialble found_a_match is set to: ")
  (print *found_a_match*)  
  (terpri))

'(defun announce-three ()
  (or (if (and (= *game_over* 0) (= *found_a_match* (not 0))) (print '(You found three in a row!))) (if (= *game_over* 0) (print '(Keep looking for a match!))))
  (terpri))

(defun my-functions ()
  (print '(ttt-functions (draw-board announce-three-in-a-row round-limit-checker display-info find-three-in-a-row change-turn attempt-to-fill-spot player-move start-game ask-to-play play-again reset-pregame-variables say-invaid)))
  (terpri))

(defun draw-board ()
  (tic-tac-toe)
  (my-ttt-list)
  (my-functions)
  '(announce-three)
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
