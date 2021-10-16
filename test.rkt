#lang racket

;(define m (- 4 8 8))
;(define x (+ 10 m 8))
;(printf "Ergebnis ist ~a ~a\n" x m)
;(define (hurz k) (printf "~a\n" k))
;(define h (lambda (k) (printf "~a another\n" k)))
;(hurz 5)
;(h 7)
;lists and pairs
;(define l (list 1 2 3))
;(car l)
;(cdr l)
;(cons 1 l)
;(append l (list 1))


; # Sorting

; # Binary Search
(define searchImpl (lambda (input pred hi lo)
                           (if (= hi lo)
                               (let
                                   ((elem (list-ref input hi)))
                                   (if (pred elem)
                                       elem
                                       null))
                               (letrec
                                   ((mid (+ (floor (/ (- hi lo) 2)) lo))
                                    (elem (list-ref input mid)))
                                   (if (pred elem)
                                       (searchImpl input pred mid lo)
                                       (searchImpl input pred hi (+ mid 1))
                                   )))))

(define search
  (lambda (input pred)
          (searchImpl input pred (- (length input) 1) 0)))

(search (list 0 1 2 3 4 5 6 7) (lambda (x) (> x 9)))

; Subsets
(define subsetsImpl
  (lambda (idx input subset)
          (if (= idx (length input))
            (list subset)
            (append
              (subsetsImpl (+ 1 idx)
                       input
                       (append subset (list (list-ref input idx))))
              (subsetsImpl (+ 1 idx)
                       input
                       subset)))))

(define subsets
  (lambda (input) (subsetsImpl 0 input (list))))

;(display (subsets (list 1 2 3)))

; # Permutations

; # Backtracking

; # Pruning

; # Meet in the middle

; # Greedy

; # Dynamic Programming

