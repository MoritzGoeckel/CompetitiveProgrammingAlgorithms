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
  (lambda (h t)
      (if (empty? t)
          h
          (foldr
            (lambda (x others)
                    (let ((res (mpermutations (append h (list x))
                                              (remove x t))))
                      (if (list? (first res))
                          (append res others)
                          (list res))))
            '()
            t))))

;(display (mpermutations '() '(1 2 3)))

; There is a build-in permutations function
;(display (permutations (list 0 1 2 3)))

; # Backtracking

; # Pruning

; # Meet in the middle

; # Greedy

; # Dynamic Programming

