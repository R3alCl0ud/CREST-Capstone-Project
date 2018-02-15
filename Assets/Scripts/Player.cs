using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {

	// mass is 0.7156686

	// starting y = 0.002999932

	// max jump = 1.770047


	// public member fields
	public GameObject Camera;

	public double yVel = 0;
	public float yPos = 0;

	// private member fields
	private Rigidbody2D rb;
	private BoxCollider2D bc2d;
	private bool canJump = false;
	private bool lose = false;

	// public member methods
	public void Start() {
		rb = GetComponent<Rigidbody2D>();
		bc2d = GetComponent<BoxCollider2D>();
	}

	public void OnCollisionEnter2D(Collision2D collision) {
		if (collision.gameObject.tag == "Platform") {
			canJump = true;

			Vector3 contactPoint = collision.contacts[0].point;
			Vector3 center = bc2d.bounds.center;
			float RectHeight = bc2d.bounds.size.y;
			bool collideFromLeft = false, collideFromRight = false;
			// collideFromTop = false, collideFromBottom = false
			// if (contactPoint.y > center.y &&
			//	(contactPoint.x < center.x + RectWidth / 2 && contactPoint.x > center.x - RectWidth / 2)) {
			//		collideFromTop = true;
			//	} else if (contactPoint.y < center.y &&
			//	    (contactPoint.x < center.x + RectWidth / 2 && contactPoint.x > center.x - RectWidth / 2)) {
			//		collideFromBottom = true;
			//	} else 
			if (contactPoint.x > center.x &&
			    (contactPoint.y < center.y + RectHeight / 2 && contactPoint.y > center.y - RectHeight / 2)) {
				collideFromRight = true;
			} else if (contactPoint.x < center.x &&
			           (contactPoint.y < center.y + RectHeight / 2 && contactPoint.y > center.y - RectHeight / 2)) {
				collideFromLeft = true;
			}

			if (collideFromLeft || collideFromRight) {
				lost();
			}
		} else if (collision.gameObject.tag == "Spike") {
			lost();
		}
	}

	public void OnCollisionExit2D(Collision2D collision) {
		if (collision.gameObject.tag == "Platform") {
			canJump = false;
		} 
	}

	private void lost() {
		lose = true;
		rb.freezeRotation = false;
		GameObject.FindGameObjectWithTag("GameController").SendMessage("GameOver");
	}

	public void Update() {
		rb.gravityScale = 2 * (1 - (transform.position.y / 20000.0f));
		if (rb.velocity.y > yVel)
			yVel = rb.velocity.y;
		if (transform.position.y > yPos)
			yPos = transform.position.y;
		if (Camera) {
			Camera.transform.position = transform.position + new Vector3(0, 0, -10);
		}
		if (!lose) {
			if ((Input.GetKey("w") || Input.GetKey("up")) && canJump) {
				rb.AddForce(Vector2.up * 350);
				canJump = false;
			}

			if ((Input.GetKey("a") || Input.GetKey("left")) && Mathf.Abs(rb.velocity.x) < 6) {
				rb.AddForce(Vector2.left * 500.0f * Time.deltaTime);
			}
			if ((Input.GetKey("d") || Input.GetKey("right")) && Mathf.Abs(rb.velocity.x) < 6) {
				rb.AddForce(Vector2.right * 500.0f * Time.deltaTime);
			}
			if (transform.position.y <= -20) {
				lost();
			}
		}
	}

}
