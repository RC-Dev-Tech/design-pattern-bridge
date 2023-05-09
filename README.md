# ![](https://drive.google.com/uc?id=10INx5_pkhMcYRdx_OO4rXNXxcsvPtBYq) Bridge 橋接模式  
> ##### 理論請自行找，網路上有很多相關的文章，這邊只關注於範例實作的部分.

---

<!--ts-->
## 目錄
* [目的](#目的)
* [使用時機](#使用時機)
* [URL結構圖](#url結構圖)
* [實作成員](#實作成員)
* [實作範例](#實作範例)
* [參考資料](#參考資料)
<!--te-->

---

## 目的
將一個大的抽象類別與其相關的實現細節分離開來，並且讓它們可以互相獨立地變化。

---

## 使用時機
當需要將抽象類別與其實現相分離，使它們可以互相獨立地變化，並且可以透過組合方式建立一個多層次的結構時，可以使用 Bridge 設計模式。

---

## URL結構圖
![](https://drive.google.com/uc?id=10yxMrVFLzEN3EOSHSqL8fw-6_cChkh1-)
> 圖片來源：[Refactoring.Guru - Bridge](https://refactoring.guru/design-patterns/bridge) 

---

## 實作成員
* Abstraction
 * 定義一個抽象類別的介面，並且維護一個指向 Implementor 物件的參考。
* RefinedAbstraction
 * 擴充 Abstraction 的介面。
* Implementor
 * 定義一個介面，供 ConcreteImplementor 實現。
* ConcreteImplementor
 * 實現 Implementor 介面。

在 Bridge 設計模式中，Abstraction 是一個抽象類別，它維護一個指向 Implementor 物件的參考，<br>
而 Implementor 是一個介面，供 ConcreteImplementor 實現。<br>
透過這樣的方式，Abstraction 可以委託 Implementor 來執行一些具體的任務，<br>
而 Implementor 也可以獨立地變化，不會受到 Abstraction 的限制。<br>
另外，如果需要新增更多的 Abstraction 或 ConcreteImplementor，<br>
只需要繼承 Abstraction 或 Implementor，而不用修改原有的程式碼。<br>

---

## 實作範例:
- [待補...]() 

---

## 參考資料
* [Wiki - Bridge Pattern](https://en.wikipedia.org/wiki/Bridge_pattern) <br>
* [Refactoring.Guru - Bridge](https://refactoring.guru/design-patterns/bridge) <br>

---

<!--ts-->
#### [目錄 ↩](#目錄)
<!--te-->
---
