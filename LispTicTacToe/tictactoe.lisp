; first is the original function I wrote as a test, to see what would happen

(defun tic-tac-toe ()
  (print 'tic-tac-toe)
  (terpri))

; defines most global variables

(defvar *false* 'false)
(defvar *game_over* *false*)
(defvar *found_a_match* *false*)
(defvar *round_counter* 0)
(defvar *mark* 'X)

(defun test-board-vals ()
  (setf *board_spots* (make-array '(9)))
  (terpri)
  (setf (aref *board_spots* 0) '1)
  (setf (aref *board_spots* 1) '2)
  (setf (aref *board_spots* 2) '3)
  (setf (aref *board_spots* 3) '4)
  (setf (aref *board_spots* 4) '5)
  (setf (aref *board_spots* 5) '6)
  (setf (aref *board_spots* 6) '7)
  (setf (aref *board_spots* 7) '8)
  (setf (aref *board_spots* 8) '9)
  (write *board_spots*)
  (terpri))

; test function list main functions I need to create and test

(defun my-t3-list ()
  (print '(t3-global-vars (round_counter mark play_again_input spot_to_fill board_spots)))
  (format t '"The variable game_over is set to: ")
  (print *game_over*)
  (format t '"and the varialble found_a_match is set to: ")
  (print *found_a_match*)  
  (terpri))

'(defun announce-three ()
  (or (if (and (= *game_over* *false*) (= *found_a_match* (not *false*))) (print '(You found three in a row!))) (if (= *game_over* *false*) (print '(Keep looking for a match!))))
  (terpri))

(defun my-functions ()
  (print '(t3-functions (draw-board announce-three-in-a-row round-limit-checker display-info find-three-in-a-row change-turn attempt-to-fill-spot player-move start-game ask-to-play play-again reset-pregame-variables say-invaid)))
  (terpri))

(defun display-info ()
  (terpri)
  (if (= *round_counter* 9) (and (and (format t '"Last Round!")) (and (terpri) (terpri))))
  (terpri)
  (format t '"Current Round is: ")
  (print *round_counter*)
  (terpri)
  (format t '"The turn currently belongs to Player: ")
  (print *mark*)
  (terpri)(terpri))

(defun change-turn ()
  (if (= 1 (mod *round_counter* 2)) (setf *mark* 'X))
  (if (= 0 (mod *round_counter* 2)) (setf *mark* 'O)))

(defun draw-board ()
  ;(tic-tac-toe)
  ;(my-t3-list)
  ;(my-functions)
  ;'(announce-three)
  (format t '"


     |     |     
  1  |  2  |  3  
_____|_____|_____
     |     |     
  4  |  5  |  6  
_____|_____|_____
     |     |     
  7  |  8  |  9  
     |     |     


")(terpri)
  ;(setf *game_over* 'true *found_a_match* 'true)
  ;(print '"The variable game_over is set to: ")
  ;(print *game_over*)
  ;(print '"and the varialble found_a_match is set to: ")
  ;(print *found_a_match*)
  (terpri))

(defun play-game ()
  (change-turn)
  (display-info)
  (draw-board)
  (test-board-vals))

(defun main-play-loop ()
  (loop while (< *round_counter* 9)
        do (setf *round_counter* (+ *round_counter* 1))
           (terpri)(terpri)
	   (draw-board)
	   (play-game)))
