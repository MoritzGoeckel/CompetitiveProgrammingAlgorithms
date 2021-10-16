#lang racket

; # Sorting

; # Binary Search

(define searchImpl
  (lambda (input pred hi lo)
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

;(display (search (list 0 1 2 3 4 5 6 7) (lambda (x) (> x 5))))

; # Subsets

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

(define mpermutations
  (lambda (front back)
      (if (empty? back)
          front
          (foldr
            (lambda (elem others)
                    (let ((result (mpermutations (append front (list elem))
                                                 (remove elem back))))
                      (if (list? (first result))
                          (append result others)
                          (list result))))
            '()
            back))))

;(display (mpermutations '() '(1 2 3)))

; There is a build-in permutations function
;(display (permutations (list 0 1 2 3)))

; # Backtracking
(define queens (lambda (n)
               (letrec ((column (make-vector n #t))
                        (diag1 (make-vector (* n 2) #t))
                        (diag2 (make-vector (* n 2) #t))
                        (count 0)
                        (impl (lambda (y)
                                      (if (= y n)
                                          (set! count (+ 1 count))
                                          (for ([x (in-range 0 n)])
                                               (let ((c x)
                                                     (d1 (+ x y))
                                                     (d2 (+ (- x y) (- n 1))))
                                                    (when (and (vector-ref column c)
                                                               (vector-ref diag1 d1)
                                                               (vector-ref diag2 d2))
                                                        (begin
                                                          (vector-set! column c #f)
                                                          (vector-set! diag1 d1 #f)
                                                          (vector-set! diag2 d2 #f)
                                                          (impl (+ 1 y))
                                                          (vector-set! column c #t)
                                                          (vector-set! diag1 d1 #t)
                                                          (vector-set! diag2 d2 #t)))))))))
                 (begin (impl 0)
                        count))))

;(queens 8)

; # Pruning

; # Meet in the middle

; # Greedy

; # Dynamic Programming

