(defun tic-tac-toe ()
  (print 'tic-tac-toe)
  (terpri))

;defines global variables

(defvar *false* 'false)
(defvar *game_over* *false*)
(defvar *found_a_match* *false*)
(defvar *round_counter* 0)

(defun my-t3-list ()
  (print '(t3-global-vars (round_counter mark play_again_input spot_to_fill board_spots)))
  (print '"The variable game_over is set to: ")
  (print *game_over*)
  (print '"and the varialble found_a_match is set to: ")
  (print *found_a_match*)  
  (terpri))

'(defun announce-three ()
  (or (if (and (= *game_over* *false*) (= *found_a_match* (not *false*))) (print '(You found three in a row!))) (if (= *game_over* *false*) (print '(Keep looking for a match!))))
  (terpri))

(defun my-functions ()
  (print '(t3-functions (draw-board announce-three-in-a-row round-limit-checker display-info find-three-in-a-row change-turn attempt-to-fill-spot player-move start-game ask-to-play play-again reset-pregame-variables say-invaid)))
  (terpri))

(defun draw-board ()
  ;(tic-tac-toe)
  ;(my-t3-list)
  ;(my-functions)
  ;'(announce-three)
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


")(terpri)
  ;(setf *game_over* 'true *found_a_match* 'true)
  ;(print '"The variable game_over is set to: ")
  ;(print *game_over*)
  ;(print '"and the varialble found_a_match is set to: ")
  ;(print *found_a_match*)
  ;(terpri)
  ;(my-test-loop)
  (terpri))

(defun main-play-loop ()
  (loop while (< *round_counter* 10)
        do (print *round_counter*)
           (setf *round_counter* (+ *round_counter* 1))
           (terpri)(terpri)
	   (draw-board)))
