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


; Sorting

; Search

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

(subsets (list 1 2 3))

